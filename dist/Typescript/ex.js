"use strict";
let numbers = [1, 2, 3, 4, 5];
let names = ["Clinton", "Joseph", "Ahmed"];
let myearnings = [1, 2, 3, 4];
let mynames = ["Clinton", "Nnamdi", "Roosevelt", "Chukwunyere"];
let matrix = [
    [1, 2, 3],
    [1, 2, 3],
    [1, 4, 5]
];
let person = ["Nnamdi", 28];
let fruits = ["Orange", "Pineapple", "Mango"];
fruits.pop();
fruits.push("Tangerine");
fruits.forEach(() => console.log(fruits));
let doubled = numbers.map((num) => num * 2);
console.log(doubled);
let evenNumbers = numbers.filter((num) => num % 2 === 0);
console.log(evenNumbers);
let mixed = ["Alice", 2, 3];
