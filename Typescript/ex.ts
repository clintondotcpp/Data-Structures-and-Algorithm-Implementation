let numbers: readonly number[] = [1, 2, 3, 4, 5];

let names: string[] = ["Clinton", "Joseph", "Ahmed"];

let myearnings: Array<number> = [1, 2, 3, 4]
let mynames: Array<string> = ["Clinton", "Nnamdi", "Roosevelt", "Chukwunyere"];

let matrix: number[][] = [
    [1, 2, 3],
    [1, 2, 3],
    [1, 4, 5]
]

let person: [string, number] = ["Nnamdi", 28];
console.log(person[1]);

let fruits: string[] = ["Orange", "Pineapple", "Mango"];
fruits.pop();
fruits.push("Tangerine");
fruits.forEach(() => console.log(fruits));

let doubled = numbers.map((num) => num * 2);
console.log(doubled);

let numberz = [1, 2, 5, 10, 11, 20, 13, 15, 51];
let evenNumbers = numberz.filter(num => num % 2 === 0);
console.log(evenNumbers);

let mixed: (string | number)[] = ["Alice", 2, 3];

let user: [string, number] = ["Alice", 30];
user.push(40);
console.log(user);

const colors: readonly string[] = ["red", "blue"];
const newColors = [...colors, "green"];
newColors.forEach(() => console.log(newColors));