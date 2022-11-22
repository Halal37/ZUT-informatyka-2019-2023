function changeCSS(cssFile, cssInd) {
    let oldlink = document.getElementsByTagName("link").item(cssInd);
    let newlink = document.createElement("link");
    newlink.setAttribute("type", "text/css");
    newlink.setAttribute("href", cssFile);
	newlink.setAttribute("rel", "stylesheet");
    // @ts-ignore: Object is possibly 'null'.
    document.getElementsByTagName("head").item(cssInd).replaceChild(newlink, oldlink);
	 console.log("Style changed");
}
const defaultstyle = document.createElement("link");
defaultstyle.setAttribute("type", "text/css");
defaultstyle.setAttribute("href", "#");
defaultstyle.setAttribute("rel", "stylesheet");
document.getElementsByTagName("head")[0].appendChild(defaultstyle);

 const style1 = document.createElement("button");
 const style2 = document.createElement("button");
function style_button(style,name, stylename){
 style.textContent = name;
 style.addEventListener("click", () => { changeCSS(stylename, 0); });
 document.getElementsByTagName("body")[0].appendChild(style);
}
style_button(style1,"styl1 ","styl1.css");
style_button(style2,"styl2 ","styl2.css");
/*const link1 = document.createElement("button");
link1.textContent = "styl1 ";
//link1.setAttribute("href", "#");
link1.addEventListener("click", () => { changeCSS("styl1.css", 0); });
document.getElementsByTagName("body")[0].appendChild(link1);
const link2 = document.createElement("button");
link2.textContent = "styl2 ";
//link2.setAttribute("href", "#");
link2.addEventListener("click", () => { changeCSS("styl2.css", 0); });
document.getElementsByTagName("body")[0].appendChild(link2);*/
