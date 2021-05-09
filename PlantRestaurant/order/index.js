var cartdiv = document.getElementById("CartItems");

function setupPage(){
    if(localStorage.length == 0)
        return 0;
    for(i = 0; i < localStorage.length; i++){
        var newdv = document.createElement("div");
        newdv.innerText = localStorage.key(i) + "    " + localStorage.getItem(localStorage.key(i));
        cartdiv.appendChild(newdv);
    }
}

if(window.addEventListener) window.addEventListener("load",setupPage, false);
else if(window.attachEvent) window.attachEvent("onload", setupPage);