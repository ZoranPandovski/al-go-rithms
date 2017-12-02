(ns solution
  (:refer-clojure :exclude [==])
  (:use [clojure.core.logic]
        [clojure.tools.macro :only [symbol-macrolet]]))

(defn lefto [x y p]
  (all
    (matche [p]
      ([[x y _ _ _]])
      ([[_ x y _ _]])
      ([[_ _ x y _]])
      ([[_ _ _ x y]]))))


(defn nexto [x y p]
  (conde
    ((lefto x y p))
    ((lefto y x p))))


; "g" is a list of attribute lists for each person, each in form:
; [Nationality, Color, Pet, Drink, Smoke]
(defn puzzleo [g]
  (symbol-macrolet
    [_ (lvar)]
    (all
      ; 0. Structural constraint:
      ; The number of people should be 5
      (== [_ _ _ _ _] g)

      ; 1. Constraints, as corresponding to the text
      ;  (following verbatim in comments):

      ; The Englishman lives in the red house
      (membero ['englishman 'red _ _ _] g)
      ; The Swede keeps dogs
      (membero ['swede _ 'dogs _ _] g)
      ; The Dane drinks tea
      (membero ['dane _ _ 'tea _] g)
      ; The green house is just to the left of the white one
      (lefto [_ 'green _ _ _] [_ 'white _ _ _] g)
      ; The owner of the green house drinks coffee
      (membero [_ 'green _ 'coffee _] g)
      ; The Pall Mall smoker keeps birds
      (membero [_ _ 'birds _ 'pallmall] g)
      ; The owner of the yellow house smokes Dunhills
      (membero [_ 'yellow _ _ 'dunhill] g)
      ; The man in the center house drinks milk
      (== [_ _ [_ _ _ 'milk _] _ _] g)
      ; The Norwegian lives in the first house
      (== [['norwegian _ _ _ _] _ _ _ _] g)
      ; The Blend smoker has a neighbor who keeps cats
      (nexto [_ _ _ _ 'blend] [_ _ 'cats _ _] g)
      ; The man who smokes Blue Masters drinks bier
      (membero [_ _ _ 'bier 'bluemasters] g)
      ; The man who keeps horses lives next to the Dunhill smoker
      (nexto [_ _ _ _ 'dunhill] [_ _ 'horses _ _] g)
      ; The German smokes Prince
      (membero ['german _ _ _ 'prince] g)
      ; The Norwegian lives next to the blue house
      (nexto ['norwegian _ _ _ _] [_ 'blue _ _ _] g)
      ; The Blend smoker has a neighbor who drinks water
      (nexto [_ _ _ _ 'blend] [_ _ _ 'water _] g)

      ; 3. Implicit constraints:
      ; Pad with information about unmentioned atoms
      (membero [_ _ 'fish _ _] g))))


(defn -main [& args]
  (let [sol (first (run* [g] (puzzleo g)))]
    (println "Solution:" sol)))
