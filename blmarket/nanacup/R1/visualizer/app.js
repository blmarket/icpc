var express = require('express');
var fs = require('fs');
var jade = require('jade');

var app = express();

app.set('views', __dirname + '/views');
app.set('view engine', 'jade');

var dataid = process.argv.pop();

var infilename = dataid + ".in";
var resfilename = dataid + ".out.mid";

var board = readinfile(infilename);
readoutfile(board, resfilename);

console.log(board);

app.get('/', function(req, res) {
  res.render('index.jade', { board: board });
});

app.listen(3000);

function readinfile(infilename) {
  var data = fs.readFileSync(infilename, 'utf-8');

  var lines = data.split('\n');

  var n = Number(lines[0].split(' ')[0]);
  var m = Number(lines[0].split(' ')[1]);

  var board = [];

  for(var i=1;i<=n;i++) {
    var tmp = [];
    for(var j=0;j<m;j++) {
      tmp.push({ value: lines[i][j] });
    }
    board.push(tmp);
  }
  return board;
}

function readoutfile(board, outfilename) {
  var data = fs.readFileSync(outfilename, 'utf-8');

  var lines = data.split('\n');
  var n = Number(lines[0]);

  for(var i=1;i<=n;i++) {
    var line = lines[i].split(' ');
    line.pop();
    for(var j=1;j<line.length;j+=2) {
      var x = Number(line[j+1]);
      var y = Number(line[j]);
      board[x][y].style = line[0] + ' something';
      board[x][y].group = line[0];
      if(board[x][y].value != line[0].charAt(j/2)) {
        board[x][y].style += ' wrong';
      }
    }
  }
}
