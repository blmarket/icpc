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

fn main() {
  let t: String = read_line();
  let v: Vec<u32> = t.split(" ").map(|x| x.parse::<u32>().unwrap()).collect();

  let (L, D, N) = (v[0], v[1], v[2]);

  let mut w: Vec<Vec<char>> = vec![];

  for i in 0..D {
    let r: String = read_line();
    w.push(r.chars().collect::<Vec<char>>());
  }
  
  for i in 0..N {
    let pat = read_line::<String>().chars().collect::<Vec<char>>();
    let mut candi: Vec<usize> = Vec::new();
    candi.resize(D as usize, 0);
    let mut it = 0;
    for j in 0..(L as usize) {
      let mut chk = |c| {
        for k in 0..candi.len() {
          if candi[k] != j { continue; }
          if c != w[k][j] { continue; }
          candi[k] += 1;
        }
      };

      if pat[it] == '(' {
        it += 1;
        while pat[it] != ')' {
          chk(pat[it]);
          it += 1;
        }
      } else {
        chk(pat[it]);
      }
      it += 1;
    // dbg(&candi); // won't work
    }
    // dbg(&candi); // work
    println!("Case #{}: {}", i+1, candi.iter().filter(|x| **x == L as usize).count());
  }
}
