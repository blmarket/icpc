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

fn pmod(mul: i32, pow: i32, m: i32) -> i32 {
  let mut ret: i32 = 1;
  for i in 0..pow {
    ret = (ret * mul) % m;
  }
  return ret;
}

fn gen(r: Range<i32>, m: i32, p: i32) {
  let c: Vec<i32> = r.clone().map(|x| pmod(m, x, p)).collect();
  dbg(c);
}

fn main() {
  // let primes = vec![3,5,7,11,13,17,23];
  let primes = vec![11];

  let r1 = 1..8;
  let r2 = 8..15;

  for p in primes {
    for i in 2..11 {
      gen(r1.clone(), i, p);
    }
  }
}
