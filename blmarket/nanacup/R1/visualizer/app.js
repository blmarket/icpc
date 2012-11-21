var express = require('express');
var fs = require('fs');
var jade = require('jade');

var app = express();

app.set('views', __dirname + '/views');
app.set('view engine', 'jade');

var dataid = process.argv.pop();

var infilename = dataid + ".in";
var resfilename = dataid + ".out.mid";

function readinfile(infilename) {
  var data = fs.readFileSync(infilename, 'utf-8');

  var lines = data.split('\n');

  var n = Number(lines[0].split(' ')[0]);
  var m = Number(lines[0].split(' ')[1]);

  var board = [];

  for(var i=1;i<=n;i++) {
    var tmp = [];
    for(var j=0;j<m;j++) {
      tmp.push(lines[i][j]);
    }
    board.push(tmp);
  }
  return board;
}

var board = readinfile(infilename);

app.get('/', function(req, res) {
  res.render('index.jade', { board: board });
});

function print_table(board) {
}
print_table(board);

app.listen(3000);
