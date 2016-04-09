use std::io;
use std::fmt::Debug;
use std::fmt::Display;
use std::str::FromStr;

fn read_line<T: FromStr + Clone>() -> T where <T as FromStr>::Err: Debug {
  let mut ret = String::new();
  io::stdin().read_line(&mut ret);
  return ret.trim().parse::<T>().unwrap().to_owned();
}

fn dbg<T: Debug>(d: T) {
  println!("{:?}", d);
}

fn process(ncase: u32) {
  println!("Case #{}: ", ncase);
}

fn main() {
  for i in 2..11 {
    let mut ii: i64 = 1;
    for j in 0..16 {
      print!("{} ", ii % 3);
      ii *= i;
    }
    println!("");
  }
}
