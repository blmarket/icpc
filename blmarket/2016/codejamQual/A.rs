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
  let N: u32 = read_line();

  let mut mask: u32 = 0;

  for i in 1..100 {
    let tmp = N * i;
    let ss = format!("{}", tmp);
    let sss = ss.chars();
    for s in sss {
      mask |= (s as u32) - ('0' as u32);
    }
    println!("{}", mask);
  }
}

fn main() {
  let T: u32 = read_line();
  for t in 1..T+1 {
    process(t);
  }
  // println!("Case #{}: {}", i+1, candi.iter().filter(|x| **x == L as usize).count());
}
