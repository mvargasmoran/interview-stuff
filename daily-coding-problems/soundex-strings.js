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

const soundex = (string) => {
  let consistentSoundString = '';
  string = string.replace(/ck/im, 'c');

  const stringArray = Array.from(string);
  let wordKey = stringArray.shift();

  string = string.replace(/[aeiouywh]+/gim, '');

  let replacedWord = string.slice(1, string.length);
  for (let i = 0 ; i < 3 ; i++) {
    if (i == 2) {
      continue;
    }
    replacedWord = replacedWord.replace(/[bfpv]+/gim, 1);
    replacedWord = replacedWord.replace(/[cgjkqsxz]+/gim, 2);
    replacedWord = replacedWord.replace(/[dt]+/gim, 3);
    replacedWord = replacedWord.replace(/[l]+/gim, 4);
    replacedWord = replacedWord.replace(/[mn]+/gim, 5);
    replacedWord = replacedWord.replace(/[r]+/gim, 6);

    if(replacedWord.length < 3) {
      replacedWord += 0;
    }
  }

  const mappedResult = `${wordKey}${replacedWord}`;
  //  console.log({string, wordKey, replacedWord, mappedResult});


  return mappedResult;
};

module.exports = soundex;
