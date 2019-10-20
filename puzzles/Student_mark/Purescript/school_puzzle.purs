module SchoolPuzzle where

import Prelude

-- This is a very simple one, assuming that they stop coming after a lesson (and cannot leave during a lesson)
-- ans = n-1

howManyKidsHadAMark :: Int -> Int
howManyKidsHadAMark numDays = (numDays - 1)


{-
Problem:

There is a school in a far far land. The teacher there teaches whatever he wishes to -- Physics,Maths,Biology, Astronomy, Philosophy, Psychology, English , Hindi and so on. There are 100 students in that school. The school has a uniques set of rules.
1. No student is allowed to question the teacher or ask the teacher anything, they will just listen and follow whatever the teacher has taught them, without questioning him or asking any doubts.
2. No student is allowed to speak to any other student. They just attend attend their classes and then go straight back to their hostel room and lock it from inside and stay there till the next day. They come out of their rooms only to attend their classes and go back as soon as  their class is over.

One night god tells the teacher that he will put a mark on at least one students head indicating that that student has now attained all the knowledge in the world and could now leave the school. The teacher tells this to his students in the class the next day.
God puts a mark on at least one student's head the next day. 
However since they cannot speak to each other, therefore other students cannot tell him that there is a mark on his head.
On the 1st day after that, all 100 students come to the class.
On the 2nd day again, all 100 students come to the class.
This goes on till the 23rd day.
On the 24th day however, some students stop coming to the class as they realised that they had a mark on their head.

How many students stopped coming to the class (i.e. had a mark on their head )? -}