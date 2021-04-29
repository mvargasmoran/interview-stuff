/*
 * This problem was asked by Grammarly.
 * Soundex is an algorithm used to categorize phonetically, such that two
 * names that sound alike but are spelled differently have the
 * same representation.
 *
 *
 * Soundex maps every name to a string consisting of one letter
 * and three numbers, like M460.
 *
 * One version of the algorithm is as follows:
 *
 * Remove consecutive consonants with the same sound
 * (for example, change ck -> c).
 * Keep the first letter. The remaining steps only apply to the rest of the string.
 * Remove all vowels, including y, w, and h.
 * Replace all consonants with the following digits:
 *
 * b, f, p, v → 1
 * c, g, j, k, q, s, x, z → 2
 * d, t → 3
 * l → 4
 * m, n → 5
 * r → 6
 *
 *
 * If you don't have three numbers yet, append zeros until you do.
 * Keep the first three numbers.
 *
 * Using this scheme, Jackson and Jaxen both map to J250.
 *
 * Implement Soundex.
 */

const alphabet = 'abcdefghijklmnopqrstuvwyxz';
const consonants = alphabet.replace(/[aeiou]/im, '');
const vowels = 'aeiou';

// This looks like fun
const soundex = (string) => {
  let consistentSoundString = '';
  // replace same sounding
  string = string.replace(/ck/im, 'c');

  // grab initial char
  const stringArray = Array.from(string);
  let wordKey = stringArray.shift();

  // remove vowels
  string = string.replace(/[aeiou]/im, '');

  console.log(string);
  let mappedResult;


  console.log(wordKey);
  //const simplifiedArray = stringArray.map(
};

soundex('MackD');
//module.exports = soundex;
