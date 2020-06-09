HAI 1.3
	BTW creates test array
	HOW IZ I createTestArray YR n AN YR arr
		n IS NOW A NUMBR

		VISIBLE "TESTING ARRAY WITH DA SIZE: " n
		IM IN YR loop UPPIN YR i TIL BOTH SAEM i AN n
			I HAS A numb ITZ PRODUKT OF i AN 2
			arr HAS A SRS i ITZ DIFF OF n AN numb
			VISIBLE DIFF OF n AN numb
		IM OUTTA YR loop
	IF U SAY SO


	BTW creates array of size n and populates it with given numbers
	HOW IZ I createArray YR n AN YR arr
		n IS NOW A NUMBR

		BOTH SAEM n AN 0
		O RLY?
			YA RLY
				FOUND YR 0
		OIC

		BTW saves array recursivly
		I HAS A numb
		VISIBLE "GIMMEH NUMBA: "
		GIMMEH numb
		numb IS NOW A NUMBR
		arr HAS A SRS DIFF OF n AN 1 ITZ numb
		I IZ createArray YR DIFF OF n AN 1 AN YR arr MKAY
	IF U SAY SO
	

	HOW IZ I partition YR arr AN YR low AN YR high
		I HAS A i ITZ DIFF OF low AN 1
		I HAS A pivot ITZ arr'Z SRS high

		BTW j from 0 to high - low
		IM IN YR loop UPPIN YR j TIL BOTH SAEM j AN DIFF OF high AN low
			BTW id = j + low
			I HAS A id ITZ SUM OF j AN low
			BTW currElem = arr[j]
			I HAS A currElem ITZ arr'Z SRS id
			I HAS A max ITZ BIGGR OF currElem AN pivot

			BOTH SAEM max AN pivot
			O RLY?
				BTW pivot > arr[j]
				YA RLY
					BTW increment i and swap arr[i] and arr[j]
					i R SUM OF i AN 1
					I HAS A tmpI ITZ arr'Z SRS i
					I HAS A tmpId ITZ arr'Z SRS id
					arr'Z SRS i R tmpId
					arr'Z SRS id R tmpI
			OIC
		IM OUTTA YR loop 

		i R SUM OF i AN 1
		I HAS A tmpI ITZ arr'Z SRS i
		I HAS A tmpHigh ITZ arr'Z SRS high
		arr'Z SRS i R tmpHigh
		arr'Z SRS high R tmpI

		FOUND YR i
	IF U SAY SO


	HOW IZ I quickSort YR arr AN YR low AN YR high
		I HAS A max ITZ BIGGR OF low AN high
		BOTH SAEM max AN high
		O RLY?
			BTW high > low
			YA RLY
				I HAS A pi ITZ I IZ partition YR arr AN YR low AN YR high MKAY
				I IZ quickSort YR arr AN YR low AN YR DIFF OF pi AN 1 MKAY
				I IZ quickSort YR arr AN YR SUM OF pi AN 1 AN YR high MKAY
		OIC
	IF U SAY SO


	BTW prepares variables
	I HAS A arr ITZ A BUKKIT
	I HAS A n
	VISIBLE "GIMMEH ARRAY SIZE (GIMMEH -1 TO TEST MISELF): "
	GIMMEH n
	n IS NOW A NUMBR

	BOTH SAEM n AN -1
	O RLY?
		BTW automated testing part
		YA RLY
			n R 10
			I IZ createTestArray YR n AN YR arr MKAY
		NO WAI
			I IZ createArray YR n AN YR arr MKAY
	OIC
	
	VISIBLE ""
	
	BTW sorts given array
	I HAS A highEnd ITZ DIFF OF n AN 1
	I IZ quickSort YR arr AN YR 0 AN YR highEnd MKAY
	
	BTW prints sorted array
    VISIBLE "UR SORTED ARRAY"
	IM IN YR loop UPPIN YR i TIL BOTH SAEM i AN n
	    VISIBLE arr'Z SRS i
	IM OUTTA YR loop

KTHXBYE