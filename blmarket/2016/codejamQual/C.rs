use std::io;
use std::collections::HashMap;
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
  return ret;
}

fn main() {
  let primes: Vec<i32> = vec![2, 3,5,7,11,13,17,19,23,29,31,37];
  // let primes = vec![3, 5];

  let N = 4;

  let r1 = (1..N-1).collect::<Vec<_>>();
  let c = r1.len() as i32;
  for mask in 0..(1<<c) {
    // dbg(mask);
    let mut fail: bool = false;
    for base in 2..11 {
      let mut found: bool = false;
      for p in primes.iter() {
        let mut tmp:i32 = (1 + pmod(base, N-1, *p)) % *p;
        for j in 0..c {
          if mask & (1<<j) != 0 {
            tmp = (tmp + pmod(base, r1[j as usize], *p));
          }
        }
        println!("{} {} {}", base, p, tmp);
        if tmp == 0 {
          found = true;
          break;
        }
      }
      if !found {
        fail = true;
        break;
      }
    }
    if !fail { 
      dbg(mask);
    }
  }
}
