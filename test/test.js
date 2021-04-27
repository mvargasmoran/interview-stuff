const assert = require("assert");
const getThirdMostCommon = require("../rockstar-coders.js");

describe('Array', function() {
  describe('#indexOf()', function() {
    it('should be "B"', function() {
      assert.equal(getThirdMostCommon('ABCDBCDCDD'), 'B');
    });
  });
});
