/*
*	Final Project VeggiGame
*	Author: Diego Esquivel
*	Date:	11/30/2019
*	File Name: script.js
*/

"use strict";//use strict prepocessor

//stuff for typeWriter() method;
var i = 0;
var txt = "L	O	D	E	I	N	G	...";
var speed = 100;

//list of questions;
var list = ['What is your name?', 
			'What is your age?', 
			'What color is the sky right now?', 
			'How many letters in the word "star"?', 
			'Do you have credit established?', 
			'Have you ever been sad?', 
			'What would you do given $2million USD?', 
			'How old were you when you first started thinking?',
			'What day is it?',
			'Do you have any kids?',
			'Do you have a middle name? If yes, what is it?',
			'How many years since you\'ve exfoliated your face?',
			'Do you like coffee?',
			'Have you ever been in love?',
			'How are you feeling at this moment?',
			'How many spirits/souls have you devoured in your lifetime(s)'];

// list of fruits that will be assigned as vegetable answer; //because no one is a vegetable
var fruit = ['Apple',
			'Blueberry',
			'Cantalope',
			'Date',
			'Evergreen Huckleberry',
			'Fig',
			'Guava',
			'Honeydew',
			'Imbe',
			'Jambolan',
			'Kiwi',
			'Lemon',
			'Mango',
			'Nectarine',
			'Olive',
			'Pear',
			'Quince',
			'Raspberry',
			'Star Fruit',
			'Tomato',
			'Ugli Fruit',
			'Vanilla Bean',
			'Watermelon',
			'Ximenia caffra fruit',
			'Yunnan Hackberry',
			'Zuchinni'
];

// vars to keep track of score and question;
var points = 0;
var multFactor = 0;
var qIndex = 0;

function keyScore(key) {
	switch(key.charAt(0)){
		case 'a':  //points += 1; break;
		case 'A':  points += 1; break
		case 'b':  //points += 2; break;
		case 'B':  points += 2; break;
		case 'c':  //points += 3; break;
		case 'C':  points += 3; break;
		case 'd':  //points += 4; break;
		case 'D':  points += 4; break;
		case 'e':  //points += 5; break;
		case 'E':  points += 5; break;
		case 'f':  //points += 6; break;
		case 'F':  points += 6; break;
		case 'g':  //points += 7; break;
		case 'G':  points += 7; break;
		case 'h':  //points += 8; break;
		case 'H':  points += 8; break;
		case 'i':  //points += 9; break;
		case 'I':  points += 9; break;
		case 'j':  //points += 10; break;
		case 'J':  points += 10; break;
		case 'k':  //points += 11; break;
		case 'K':  points += 11; break;
		case 'l':  //points += 12; break;
		case 'L':  points += 12; break;
		case 'm':  //points += 13; break;
		case 'M':  points += 13; break;
		case 'n':  //points += 14; break;
		case 'N':  points += 14; break;
		case 'o':  //points += 15; break;
		case 'O':  points += 15; break;
		case 'p':  //points += 16; break;
		case 'P':  points += 16; break;
		case 'q':  //points += 17; break;
		case 'Q':  points += 17; break;
		case 'r':  //points += 18; break;
		case 'R':  points += 18; break;
		case 's':  //points += 19; break;
		case 'S':  points += 19; break;
		case 't':  //points += 20; break;
		case 'T':  points += 20; break;
		case 'u':  //points += 21; break;
		case 'U':  points += 21; break;
		case 'v':  //points += 22; break;
		case 'V':  points += 22; break;
		case 'w':  //points += 23; break;
		case 'W':  points += 23; break;
		case 'x':  //points += 24; break;
		case 'X':  points += 24; break;
		case 'y':  //points += 25; break;
		case 'Y':  points += 25; break;
		case 'z':  //points += 26; break;
		case 'Z':  points += 26; break;
		default:  multFactor += Number(key);
	}
}// end function keyScore() which augments appropriate variable for calculating final score;

function validateLetters() {
	var numberInputs = document.querySelectorAll("#answer input[type=text]");
	var currentElement
	var lettersInputs = $("#newItem").val();
	var elementCount = lettersInputs.length;
	var patt1 = /[a-z A-Z]/g; 
	var countResult = lettersInputs.match(patt1);
	var errorDiv = document.getElementById("errorText");
	var notEmptyValid = true;
	var allLettersValid = true;
	try{
		currentElement = numberInputs[0];
		if(countResult == null){
			currentElement.style.background = "rgb(255,233,233)";
			notEmptyValid = false;
			throw "Please enter letters.";
		}// end if no input;
		else if(countResult.length != elementCount){
			currentElement.style.background = "rgb(255,233,233)";
			allLettersValid = false;
			throw "Please use only letters";
		}// end if letters match pattern != total chars input;
		else{
			keyScore($("#newItem").val());
			document.getElementById("newItem").style.background = "white";
			//throw "" + points;
		}// end else submit input to keyScore and 'clean' input box;
		errorDiv.style.display = "none";
		errorDiv.innerHTML = "";
	}
	catch(msg){
		errorDiv.style.display = "block";
		errorDiv.innerHTML = msg;// reveal message containing points total to the moment;
		if(notEmptyValid == false || allLettersValid == false)
			return false;// end if not valid return false;
	}
	return true;
}// end function validateLetters() which returns true to checkValidity() iff only letters and ' ' used in letter requested question;
  
/* validate number fields for older browsers */
function validateNumbers(){
	var numberInputs = document.querySelectorAll("#answer input[type=text]");
	var elementCount = numberInputs.length;
	var numErrorDiv = document.getElementById("numErrorText");
	var numbersValidity = true;
	var currentElement;
	var lengthValidity = true;
	try{
		for(var i = 0; i < elementCount; i++){
			//validate all input elements of type "number" in fieldset
			currentElement = numberInputs[i];
			if($("#newItem").val().length > 2){
				currentElement.style.background = "rgb(255,233,233)";
				lengthValidity = false;
			}
			else if(isNaN(currentElement.value) || (currentElement.value === "")){
				currentElement.style.background = "rgb(255,233,233)";
				numbersValidity = false;
			}else{
				currentElement.style.background = "white";
			}
		}
		if(numbersValidity === false){
			throw "Please use only numbers.";
		}
		if(lengthValidity === false){
			throw "Please use a reasonable number." + document.getElementById("newItem").value.length;
		}
		if(numbersValidity === true && lengthValidity === true)
		{
			keyScore($("#newItem").val());
			//throw "" + multFactor;
		}
		numErrorDiv.style.display = "none";
		numErrorDiv.innerHTML = "";
	}
	catch(msg){
		numErrorDiv.style.display = "block";
		numErrorDiv.innerHTML = msg;
		if(numbersValidity === false || lengthValidity === false)
			return false;
	}
	return true;
}// end function validateNumbers() which returns true to checkValidity() iff only numbers in requested question;

function checkValidity() {
	if(qIndex === 1)
		return validateLetters();
	else if(qIndex === 2)
		return validateNumbers();
	else if(qIndex === 3)
		return validateLetters();
	else if(qIndex === 4)
		return validateNumbers();
	else if(qIndex === 5)
		return validateLetters();
	else if(qIndex === 6)
		return validateLetters();
	else if(qIndex === 7)
		return validateLetters();
	else if(qIndex === 8)
		return validateNumbers();
	else if(qIndex === 9)
		return validateLetters();
	else if(qIndex === 10)
		return validateLetters();
	else if(qIndex === 11)
		return validateLetters();
	else if(qIndex === 12)
		return validateNumbers();
	else if(qIndex === 13)
		return validateLetters();
	else if(qIndex === 14)
		return validateLetters();
	else if(qIndex === 15)
		return validateLetters();
	else if(qIndex === 16)
		return validateNumbers();
	
}// end function checkValidity() which verifies appropriate input based on question #;

function typeWriter() {
	if(i < txt.length){
		document.getElementById('loading').innerHTML += txt.charAt(i);
		i++;
		setTimeout(typeWriter,speed);
	}
	else{
		i = 0;
		document.getElementById('loading').innerHTML = "";
	}
}// end function typeWriter() which simulates typeWriter 'LOADING...' while quiz results calculated;

function whatFruit() {
	var numErrorDiv = document.getElementById("numErrorText");
	var loading = document.getElementById('loading');
	var ever = document.getElementById("Quiz");
	//ever.style.display = "none";
	loading.style.display = "block";
	$("#Quiz").hide();
	$("h2").html("");
	try{
		typeWriter();
		setTimeout(typeWriter,speed*(txt.length+1));
		setTimeout(typeWriter,speed*((txt.length+1)*2));
		if(multFactor!=0)
			points *= multFactor;
		//throw "Points: " + points + "	Your a " + fruit[points%26];
		numErrorDiv.style.display = "none";
		numErrorDiv.innerHTML = "";
		setTimeout(function(){$("h2").html("You're a(n) " + fruit[points%26]);},speed*((txt.length+1)*3));
		//$("h2").html("You're a(n) " + fruit[points%26]);
	}
	catch(msg){
		numErrorDiv.innerHTML = msg;
	}
}// end function whatFruit() which calls to function typeWriter, calculates final score, and produces quiz results;

function generateList()	{
	var valid = checkValidity();
	if(valid == true && qIndex < list.length){
		if(qIndex < list.length){
		var newQ = "Question #" + (1+qIndex) + " " + list[qIndex];
		qIndex++;
		$("h2").html(newQ);
		}
	}
	else if(valid == true && qIndex >= 16){
		whatFruit();
	}
	$("#newItem").val("");
}// end function generateList() which toggles question shown in 'h2' after validation OR calls to reveal quiz result;

function createEventListener()	{
	var addButton = document.getElementById("button");
	var survey = document.getElementById("Quiz");
	if(addButton.addEventListener)	{
		addButton.addEventListener("click", generateList, false);
		survey.addEventListener("submit", function(event){
			generateList(); 
			event.preventDefault();
		}, false);
	} else if(addButton.attachEvent)	{
		addButton.attachEvent("onclick", generateList);
		survey.addEventListener("submit", function(event){
			generateList();
			event.preventDefault();
		});
	}
}// end function createEventListener() to create event listeners for button, 'enter' key;

function setupPage() {
	createEventListener();
	var newQ = "Question #" + (1+qIndex) + " " + list[qIndex];
	qIndex++;
	$("h2").html(newQ);
	document.getElementById("MC1").style.display = "none";
}// end function setupPage() which sets up page through calls to createEventListener(), starting first question, and hiding unneccesary inputs;



if(window.addEventListener) window.addEventListener("load",setupPage, false);
else if(window.attachEvent) window.attachEvent("onload", setupPage);
// end onload even listeners;


