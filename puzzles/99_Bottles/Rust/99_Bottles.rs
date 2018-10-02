// Sings '99 Bottles of Beer'
fn main()
{
    for bottle in (1..100).rev()
    {
        if bottle > 1
        {
            println!("{} bottles of beer on the wall, {} bottles of beer.", bottle, bottle);
            if bottle > 2
            {
                println!("Take one down and pass it around, {} bottles of beer on the wall.", bottle - 1);
            }
            else
            {
                println!("Take one down and pass it around, 1 bottle of beer on the wall.");
            }
        }
        else
        {
            println!("1 bottle of beer on the wall, 1 bottle of beer.");
            println!("Take one down and pass it around, no more bottles of beer on the wall.");
        }
        println!("");
    }
    println!("No more bottles of beer on the wall, no more bottles of beer.");
    println!("Go to the store and buy some more, 99 bottles of beer on the wall.\n");
}
