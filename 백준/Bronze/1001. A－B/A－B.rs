use std::io;

fn main() {
    let mut input_num = String::new();

    io::stdin().read_line(&mut input_num).expect("input_num reading error");

    let numbers: Vec<i32> = input_num.split_whitespace().map(|s| s.parse().unwrap()).collect();
    let sum: i32 = numbers[0] - numbers[1];

    println!("{}", sum);
}