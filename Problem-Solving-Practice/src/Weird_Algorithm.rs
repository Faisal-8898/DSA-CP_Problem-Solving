use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("failed to read line");
    let number: i32 = input
        .trim()
        .parse()
        .expect("Invalid input. Please enter a valid integer.");
    println!("{}", number);
}
