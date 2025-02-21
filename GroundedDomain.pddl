(define (domain elevators)
(:requirements :typing :durative-actions)
(:types
  #object
  elevator - #object
  person - #object
  floor - #object
)
(:constants
  f0 - floor
  f1 - floor
  p0 - person
  e0 - elevator
)
(:predicates
  (person-on-floor ?p - person ?f - floor)
  (stopped ?e - elevator)
  (person-in-elevator ?p - person ?e - elevator)
  (elevator-on-floor ?e - elevator ?f - floor)
)
(:durative-action move-elevator_e0_f1_f0
:parameters ( )
:duration (= ?duration 4)
:condition
  (at start (elevator-on-floor e0 f1))
:effect (and 
  (at start (not (elevator-on-floor e0 f1)))
  (at start (not (stopped e0)))
  (at end (elevator-on-floor e0 f0))
  (at end (stopped e0)))
)
(:durative-action move-elevator_e0_f1_f1
:parameters ( )
:duration (= ?duration 4)
:condition
  (at start (elevator-on-floor e0 f1))
:effect (and 
  (at start (not (elevator-on-floor e0 f1)))
  (at start (not (stopped e0)))
  (at end (elevator-on-floor e0 f1))
  (at end (stopped e0)))
)
(:durative-action enter-elevator_p0_e0_f0
:parameters ( )
:duration (= ?duration 4)
:condition (and 
  (at start (elevator-on-floor e0 f0))
  (at start (stopped e0))
  (at start (person-on-floor p0 f0)))
:effect (and 
  (at start (not (person-on-floor p0 f0)))
  (at end (person-in-elevator p0 e0)))
)
(:durative-action move-elevator_e0_f0_f0
:parameters ( )
:duration (= ?duration 4)
:condition
  (at start (elevator-on-floor e0 f0))
:effect (and 
  (at start (not (elevator-on-floor e0 f0)))
  (at start (not (stopped e0)))
  (at end (elevator-on-floor e0 f0))
  (at end (stopped e0)))
)
(:durative-action move-elevator_e0_f0_f1
:parameters ( )
:duration (= ?duration 4)
:condition
  (at start (elevator-on-floor e0 f0))
:effect (and 
  (at start (not (elevator-on-floor e0 f0)))
  (at start (not (stopped e0)))
  (at end (elevator-on-floor e0 f1))
  (at end (stopped e0)))
)
(:durative-action leave-elevator_p0_e0_f1
:parameters ( )
:duration (= ?duration 4)
:condition (and 
  (at start (elevator-on-floor e0 f1))
  (at start (stopped e0))
  (at start (person-in-elevator p0 e0)))
:effect (and 
  (at start (not (person-in-elevator p0 e0)))
  (at end (person-on-floor p0 f1)))
)
(:durative-action leave-elevator_p0_e0_f0
:parameters ( )
:duration (= ?duration 4)
:condition (and 
  (at start (elevator-on-floor e0 f0))
  (at start (stopped e0))
  (at start (person-in-elevator p0 e0)))
:effect (and 
  (at start (not (person-in-elevator p0 e0)))
  (at end (person-on-floor p0 f0)))
)
(:durative-action enter-elevator_p0_e0_f1
:parameters ( )
:duration (= ?duration 4)
:condition (and 
  (at start (elevator-on-floor e0 f1))
  (at start (stopped e0))
  (at start (person-on-floor p0 f1)))
:effect (and 
  (at start (not (person-on-floor p0 f1)))
  (at end (person-in-elevator p0 e0)))
)
)
