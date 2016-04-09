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

fn genmask(r: Vec<i32>) -> Vec<Vec<i32>> {
  let mut ret: Vec<Vec<i32>> = vec![];
  let c: i32 = r.len() as i32;
  for i in 0..(1<<c) {
    let mut tmp: Vec<i32> = vec![];
    for j in 0..c {
      if i & (1<<j) != 0 {
        tmp.push(r[j as usize]);
      }
    }
    ret.push(tmp);
  }
  return ret;
}

fn main() {
  // let primes: Vec<i32> = vec![3,5,7,11,13,17,23];
  let primes = vec![3, 5];

  let N = 6;

  let r1 = 1..N/2;
  let r2 = N/2..N-1;

  let m1 = genmask(r1.clone().collect());
  let m2 = genmask(r2.clone().collect());

  let base = 2..11;

  let rr1 = m1.iter().map(|v| {
    return primes.iter().map(|p| {
      let tmp = base.clone().map(|b| {
        return v.iter().map(|x| pmod(b, *x, *p)).fold(0, |a,b| (a + b) % *p);
      }).collect::<Vec<_>>();
      return (p, tmp);
    }).collect::<Vec<_>>();
  }).collect::<Vec<_>>();
  dbg(rr1);
}
