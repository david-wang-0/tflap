#include "state.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

TState::TState(unsigned int numSASVars, unsigned int numNumVars) {
	this->numSASVars = numSASVars;
	this->numNumVars = numNumVars;
	state = new TValue[numSASVars];
	numState = new float[numNumVars];
}

TState::TState(SASTask* task) : TState(task->variables.size(), task->numVariables.size()) {	// Create the initial state
	for (unsigned int i = 0; i < numSASVars; i++) {
		state[i] = task->initialState[i];
	}
	for (unsigned int i = 0; i < numNumVars; i++) {
		numState[i] = task->numInitialState[i];
	}
}

TState::TState(TState* s) {
	this->numSASVars = s->numSASVars;
	this->numNumVars = s->numNumVars;
	state = new TValue[numSASVars];
	numState = new float[numNumVars];
	for (unsigned int i = 0; i < numSASVars; i++) state[i] = s->state[i];
	for (unsigned int i = 0; i < numNumVars; i++) numState[i] = s->numState[i];
}

TState::~TState() {
	delete[] state;
	delete[] numState;
}

/*
float TState::computeActionDuration(SASAction* a) {
	if (a->duration.size() == 1) {
		SASDuration* duration = &(a->duration[0]);
		return evaluateDuration(duration);
	}
	else {
		cout << "Duration intervals not supported yet" << endl;
		assert(false);
		return EPSILON;
	}
}

// Evaluates a duration expression
float TState::evaluateDuration(SASDuration* duration) {
	if (duration->time == 'E' || duration->time == 'A') {
		cout << "At-end or over-all durations not supported yet" << endl;
		assert(false);
	}
	if (duration->comp != '=') {
		cout << "Inequalities in duration not supported yet" << endl;
		assert(false);
	}
	return evaluateNumericExpression(&(duration->exp));
}

// Evaluates a numeric expression
float TState::evaluateNumericExpression(SASNumericExpression* exp) {
	if (exp->type == 'N') return exp->value;			// NUMBER
	if (exp->type == 'V') return numState[exp->var];	// VAR
	if (exp->type == 'D' || exp->type == '#') {
		cout << "#t in duration not supported yet" << endl;
		assert(false);
	}
	float res = evaluateNumericExpression(&(exp->terms[0]));
	for (unsigned int i = 1; i < exp->terms.size(); i++) {
		switch (exp->type) {
		case '+': res += evaluateNumericExpression(&(exp->terms[i]));	break;	// SUM
		case '-': res -= evaluateNumericExpression(&(exp->terms[i]));	break;	// SUB
		case '*': res *= evaluateNumericExpression(&(exp->terms[i]));	break;	// MUL
		case '/': {																		// DIV
					  float v = evaluateNumericExpression(&(exp->terms[i]));	break;
					  if (v != 0) res /= v;
					  else res = FLOAT_INFINITY;
		}
			break;
		}
	}
	return res;
}


// Checks if a numeric condition holds in the given numeric state
bool TState::holdsNumericCondition(SASNumericCondition& cond) {
	float v1 = evaluateNumericExpression(&(cond.terms[0]));
	float v2 = evaluateNumericExpression(&(cond.terms[1]));
	//cout << "Condition: " << v1 << " " << cond.comp << " " << v2 << endl;
	switch (cond.comp) {
		case '=':	return v1 == v2;
		case '<':	return v1 < v2;
		case 'L':	return v1 <= v2;
		case '>':	return v1 > v2;
		case 'G':	return v1 >= v2;
		case 'N':	return v1 != v2;
	}
	return false;
}
*/

std::string TState::toString(SASTask* task) {
	std::string res = "STATE\n";
	for (unsigned int i = 0; i < numSASVars; i++) {
		res += "* " + task->variables[i].name + " = " + task->values[state[i]].name + "\n";
	}
	for (unsigned int i = 0; i < numNumVars; i++) {
		res += "* " + task->numVariables[i].name + " = " + std::to_string(numState[i]) + "\n";
	}
	return res;
}
