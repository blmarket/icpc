use std::io;
use std::ops::Range;
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

fn gen(r: Range<i32>) {
  let c = r.count();
  dbg(c);
}

fn main() {
  let primes = vec![3,5,7,11,13,17,23];

  let r1 = 1..8;
  let r2 = 8..15;

  gen(r1);
}
