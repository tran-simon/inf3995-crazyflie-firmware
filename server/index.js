const {exec} = require("child_process");
const express = require('express');

const app = express();
const port = process.env.PORT || 9000;

const execOptions = {
  cwd: '../'
}

app.get('/', (req, res) => {
  res.status(200).send('Connected to firmware server');
});

const runCommand = (command, res, errorMessage = "Error: ")=>{
  exec(command, execOptions, (error, stdout, stderr) => {
    if(error){
      console.error(errorMessage, error)
      res.status(500).send(stderr)
    }
    else{
      res.status(200).send(stdout)
    }
  })
}

app.get('/build', (req, res) => {
  runCommand('make', res, "Error while building: ")
})

app.get('/clean', (req, res) => {
  runCommand('make clean', res, "Error while cleaning: ")
})

app.get('/flash', (req, res) => {
  runCommand('make cload', res, "Error while cleaning: ")
})



app.listen(port, () => {
  console.log(`Server listening on port ${port}`)
});

