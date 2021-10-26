import scala.annotation.tailrec

import scala.io.StdIn

/**
 * A state machine that will "give the user a quarter" when the state of the machine,
 * represented as a monetary balance, reaches 25¢. The machine does not track the coins
 * that were deposited to reach its current balance, so it theoretically requires no
 * memory.
 */
object CoinStateMachine {
	/**
	 * A map of coins to their respective values.
	 */
	val values: Map[String, Int] = Map(
		"penny" -> 1,
		"nickel" -> 5,
		"dime" -> 10,
		"quarter" -> 25
	)

	/**
	 * Deposit a coin into this state machine.
	 *
	 * This function recursively calls itself until the balance is greater than or equal to 25, at which it tells
	 * the user that they have a quarter.
	 *
	 * @param balance the current balance of the state machine
	 */
	@tailrec
	def deposit(balance: Int = 0): Unit = {
		if (balance >= 25) {
			println("Thanks, here's your quarter")
		} else {
			println("Balance: " + balance)
			deposit(
				balance + values.getOrElse(StdIn.readLine("Please insert a coin (penny, nickel, dime, quarter): "), {
					println("Sorry, that's not a coin")
					0
				})
			)
		}
	}

	/**
	 * Entry point for the state machine.
	 * @param args command line arguments (not used)
	 */
	def main(args: Array[String]) = deposit()
}
