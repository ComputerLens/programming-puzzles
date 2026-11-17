const x = NaN;
const y = x + 1;
const s = new Set();

s.add(x);
s.add(x);
s.add(y);

console.log("size           :", s.size);
console.log("has x          :", s.has(x));
console.log("has stored y   :", s.has(y));
console.log("has fresh x + 1:", s.has(x + 1));
