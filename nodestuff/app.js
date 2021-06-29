import Emitter from './emitter.js';


const emtr = new Emitter();

emtr.on('greet', function() {
  console.log('Somewhere, someone said hello');
});

emtr.on('greet', function() {
  console.log('A greeting event was listened');
});

console.log('Hello');

emtr.emit('greet');
