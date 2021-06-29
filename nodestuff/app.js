import Emitter from 'events';
import conf from './config.js';

const events = conf.events;
const Emtr = new Emitter();

Emtr.on(events.GREET, function() {
  console.log('Somewhere, someone said hello');
});

Emtr.on(events.GREET, function() {
  console.log('A greeting event was listened');
});

console.log('App Run...');

Emtr.emit(events.GREET);
