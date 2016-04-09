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
  print!("Case #{}: ", ncase);
  let ps = read_line::<String>().split(" ")
    .map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
  let (K,C,S) = (ps[0], ps[1], ps[2]);

  println!("{} {} {}", K,C,S);
}

fn main() {
  let T: u32 = read_line();
  for t in 1..T+1 {
    process(t);
  }
}
