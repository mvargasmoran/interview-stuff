const soundex = require('./soundex-strings.js');
it('checks if soundex works alright', () => {
  expect(soundex('Jackozixn')).toBe('J250');
  expect(soundex('Jackson')).toBe('J250');
  expect(soundex('Jaxen')).toBe('J250');
});
