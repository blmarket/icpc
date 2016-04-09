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

fn gen(K: i32, v: &Vec<i32>, x: usize, cur: i64) -> i64 {
  if (x == v.len()) {
    return cur;
  }
  return gen(K, &v, x+1, cur * (K as i64) + v[x] as i64);
}

fn process(ncase: u32) {
  print!("Case #{}: ", ncase);
  let ps = read_line::<String>().split(" ")
    .map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
  let (K,C,S) = (ps[0], ps[1], ps[2]);

  if (C*S < K) {
    println!("IMPOSSIBLE");
    return;
  }

  let mut it = 0;
  for i in 0..S {
    let mut v: Vec<i32> = vec![];
    for j in 0..C {
      v.push(it % K);
      if (it < K) {
        it += 1;
      }
    }

    print!("{} ", gen(K, &v, 0, 0) + 1);
    if (it == K) {
      break;
    }
  }
  println!("");
}

fn main() {
  let T: u32 = read_line();
  for t in 1..T+1 {
    process(t);
  }
}
