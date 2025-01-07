
var TimeLimitedCache = function() {
  this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
  const hit = this.cache.has(key) && this.cache.get(key)[1] > Date.now();
  this.cache.set(key, [value, Date.now() + duration]);
  return hit;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
  if (!this.cache.has(key)) return -1;
  const [value, expiredAt] = this.cache.get(key);
  return expiredAt > Date.now() ? value : -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
  return [...this.cache.keys()].reduce((count, key) => {
    return this.cache.get(key)[1] > Date.now() ? ++count : count;
  }, 0);
};