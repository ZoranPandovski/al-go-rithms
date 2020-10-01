HAI 1.3
	BTW creates test array
	HOW IZ I createTestArray YR n
		I HAS A arr ITZ A BUKKIT
		n IS NOW A NUMBR

		VISIBLE "TESTING ARRAY WITH DA SIZE: " n
		IM IN YR loop UPPIN YR i TIL BOTH SAEM i AN n
			I HAS A numb ITZ PRODUKT OF i AN 2
			arr HAS A SRS i ITZ numb
			VISIBLE numb
		IM OUTTA YR loop

		FOUND YR arr
	IF U SAY SO


	BTW creates array of size n and populates it with given numbers
	HOW IZ I createArray YR n
		I HAS A arr ITZ A BUKKIT
		n IS NOW A NUMBR
		IM IN YR loop UPPIN YR i TIL BOTH SAEM i AN n
			I HAS A numb ITZ A NUMBR
			VISIBLE "GIMMEH NUMBA#" i ": "
			GIMMEH numb
			arr HAS A SRS i ITZ numb
		IM OUTTA YR loop

		FOUND YR arr
	IF U SAY SO


	BTW checks if array is sorted and returns 1 if it is, 0 otherwise
	HOW IZ I checkSorted YR arr AN YR n
		n IS NOW A NUMBR
		n R DIFF OF n AN 1

		IM IN YR loop UPPIN YR i TIL BOTH SAEM i AN n
			I HAS A nextId ITZ SUM OF i AN 1
			I HAS A curr ITZ arr'Z SRS i
			I HAS A next ITZ arr'Z SRS nextId

			curr IS NOW A NUMBR
			next IS NOW A NUMBR

			I HAS A max ITZ BIGGR OF curr AN next
			BOTH SAEM max AN curr
			O RLY?
				YA RLY
					FOUND YR FAIL
			OIC

		IM OUTTA YR loop

		FOUND YR WIN
	IF U SAY SO


	BTW searches through the list
	HOW IZ I binarySearch YR arr AN YR low AN YR high AN YR searching AN YR recId
		BOTH SAEM low AN high
		O RLY?
			BTW low = high
			YA RLY
				I HAS A curr ITZ arr'Z SRS low
				curr IS NOW A NUMBR
				BOTH SAEM curr AN searching
				O RLY?
					YA RLY
						BTW arr[low] = searching
						FOUND YR low
					NO WAI
						FOUND YR -1
				OIC
			BTW else
			NO WAI
				I HAS A max ITZ BIGGR OF low AN high
				BOTH OF max AN high
				O RLY?
					BTW high > low
					YA RLY
						I HAS A sum ITZ SUM OF low AN high
						I HAS A mid ITZ QUOSHUNT OF sum AN 2
						mid IS NOW A NUMBR

						BTW get arr[mid]
						I HAS A curr ITZ arr'Z SRS mid
						curr IS NOW A NUMBR

						BOTH SAEM curr AN searching
						O RLY?
							BTW arr[mid] = searching
							YA RLY
								FOUND YR mid
							NO WAI
								I HAS A max ITZ BIGGR OF curr AN searching
								BTW arr[mid] > searching
								BOTH SAEM max AN curr
								O RLY?
									YA RLY
										I HAS A higher ITZ DIFF OF mid AN 1
										I HAS A result ITZ I IZ binarySearch YR arr AN YR low AN YR higher AN YR search AN YR recId MKAY
										FOUND YR result
									NO WAI
										I HAS A lower ITZ SUM OF mid AN 1
										I HAS A result ITZ I IZ binarySearch YR arr AN YR lower AN YR high AN YR search AN YR recId MKAY
										FOUND YR result
								OIC
						OIC
					NO WAI
						FOUND YR -1
				OIC	
		OIC
	IF U SAY SO


	BTW prepares variables
	I HAS A n ITZ 0
	I HAS A arr ITZ A BUKKIT
	I HAS A search

	VISIBLE "GIMMEH SORTED ARRAY SIZE (GIMMEH -1 TO TEST MISELF): "
	GIMMEH n
	n IS NOW A NUMBR

	BOTH SAEM n AN -1
	O RLY?
		BTW automated testing part
		YA RLY	
			n R 10
			arr R I IZ createTestArray YR n MKAY
			VISIBLE ""

			search R 14
			VISIBLE "SEARCH VALUE = 14"
			search IS NOW A NUMBR
		BTW user interacted part
		NO WAI
			arr R I IZ createArray YR n MKAY
			VISIBLE ""

			VISIBLE "GIMMEH VALUE TO SEARCH: "
			GIMMEH search
			search IS NOW A NUMBR
			
	OIC
	

	I HAS A sorted ITZ I IZ checkSorted YR arr AN YR n MKAY
	BOTH SAEM sorted AN WIN
	O RLY?
		BTW if the array is sorted
		YA RLY
			I HAS A highEnd ITZ DIFF OF n AN 1
			I HAS A resId ITZ I IZ binarySearch YR arr AN YR 0 AN YR highEnd AN YR search AN YR 0 MKAY

			BTW prints result
			BOTH SAEM resId AN -1
			O RLY?
				YA RLY
					VISIBLE "COULD NOT FIND " search " IN DA ARRAY..."
				NO WAI
					I HAS A curr ITZ arr'Z SRS resId
					curr IS NOW A NUMBR
					VISIBLE "" search " WAS #" resId " IN DA ARRAY"
			OIC
		NO WAI
			VISIBLE "DA GIVEN ARRAY IS NOT SORTED!"
	OIC	
KTHXBYE