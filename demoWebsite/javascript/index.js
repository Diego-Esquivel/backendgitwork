document.getElementById('date').innerHTML = new Date().toDateString();
var slideIndex = 1;
var inc = 1;
showSlides();
//start();

function showSlides() {
  var i;
  var slides = document.getElementsByClassName("image-section");
  for (i = 0; i < slides.length; i++) {
    slides[i].style.display = "none";
  }
  
  if (slideIndex > slides.length) {slideIndex = 1;}
  if(slideIndex <= 0){slideIndex = slides.length;}
  slides[slideIndex-1].style.display = "block";
  //plusSlides();
}
function plusSlides(){
	clearInterval(rep);
	slideIndex++;
	showSlides(); 
	rep = setInterval(function(){
if(pSlide.addEventListener("click", deqSlides, false)) slideIndex--;
else if(nSlide.addEventListener("click", plusSlides, false)) slideIndex++;
else if(cSlide1.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide2.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide3.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide4.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else {slideIndex++; showSlides();}
},4000);
}
function deqSlides(){
	clearInterval(rep);
	slideIndex--;
	showSlides(); 
	rep = setInterval(function(){
if(pSlide.addEventListener("click", deqSlides, false)) slideIndex--;
else if(nSlide.addEventListener("click", plusSlides, false)) slideIndex++;
else if(cSlide1.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide2.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide3.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide4.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else {slideIndex++; showSlides();}
},4000);
}
function currentSlide(){
	clearInterval(rep);
	slideIndex = inc;
	showSlides();
	rep = setInterval(function(){
if(pSlide.addEventListener("click", deqSlides, false)) slideIndex--;
else if(nSlide.addEventListener("click", plusSlides, false)) slideIndex++;
else if(cSlide1.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide2.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide3.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide4.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else {slideIndex++; showSlides();}
},4000);
}
var pSlide = document.getElementById("prev");
var nSlide = document.getElementById("next");
var cSlide1 = document.getElementById("dot1");
var cSlide2 = document.getElementById("dot2");
var cSlide3 = document.getElementById("dot3");
var cSlide4 = document.getElementById("dot4");
var rep = setInterval(function(){
if(pSlide.addEventListener("click", deqSlides, false)) slideIndex--;
else if(nSlide.addEventListener("click", plusSlides, false)) slideIndex++;
else if(cSlide1.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide2.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide3.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else if(cSlide4.addEventListener("click", currentSlide, false)) slideIndex = slideIndex;
else {slideIndex++; showSlides();}
},4000);


function showDrop(){
	showSide();
	var getDropdownConts = document.getElementById("dropdown-conts");
	if(getDropdownConts.style.display != "block") getDropdownConts.style.display = "block";
	else getDropdownConts.style.display = "none";
}

function showSide(){
	var statSide = document.getElementById("sidenav");
	statSide.classList.toggle("sidenavClick");
	statSide = document.getElementById("logo");
	statSide.classList.toggle("sidemenuClick");
	statSide = document.getElementById("side-conts");
	statSide.classList.toggle("sidemenuClick");
	statSide = document.getElementById("nav");
	statSide.classList.toggle("navClick");
}
