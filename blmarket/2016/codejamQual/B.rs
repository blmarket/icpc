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
  let S: String = read_line();
  let v: Vec<char> = S.chars().collect();

  let mut ret: i32 = 0;

  for s in v.windows(2) {
    if (s[0] != s[1]) {
      ret += 1;
    }
  }
  match v.last() {
    Some(&'-') => ret += 1,
    Some(x) => (),
    None => (),
  }
  println!("{}", ret);
}

fn main() {
  let T: u32 = read_line();
  for t in 1..T+1 {
    process(t);
  }
}
