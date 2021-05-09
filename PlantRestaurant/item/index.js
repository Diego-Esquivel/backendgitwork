const url = document.location.href;
const index_1 = url.indexOf("?q");
var image_prop = "";
for(i = index_1+3; i < url.length; i++){
    image_prop += url[i];
}


function setImage() { 
    const imagediv = document.getElementsByTagName("img");
    imagediv[0].src = image_prop + '.png';
}

function setPrice(){
    var pricediv = document.getElementsByName("price");
    if(image_prop == "Cannabutter")
        pricediv[0].innerText = "Price: $100 /g";
    else if(image_prop == "Cannabrownie")
        pricediv[0].innerText = "Price: 27 /Canna Brownie";
}

function setDescription() {
    var descdiv = document.getElementsByName("description");
    if(image_prop == "Cannabutter")
        descdiv[0].innerText = "Description<br>- Delectable CannaButter made with a variety of strain";
    else if(image_prop == "Cannabrownie")
        descdiv[0].innerText = "Description<br>- Delectable Brownie made with a variety of strain";
}

function setItem(){
    var itemdiv = document.getElementsByTagName('h3');
    itemdiv[0].innerText = image_prop;
    setImage();
    setPrice();
    setDescription();
}

function setupPage() {
    setItem();
}// end function setupPage() which sets up page through calls to createEventListener(), starting first question, and hiding unneccesary inputs;

var slider = document.getElementById("slider");
var output = document.getElementById("quanta");
output.innerText = slider.value;

slider.oninput = function() {
    output.innerText = this.value;
}

var addtocart = document.getElementById("AddtoCart");


addtocart.onclick = function() {
    localStorage.setItem(image_prop, +slider.value + +localStorage.getItem(image_prop));
    console.log(localStorage.getItem(image_prop));
}

if(window.addEventListener) window.addEventListener("load",setupPage, false);
else if(window.attachEvent) window.attachEvent("onload", setupPage);
