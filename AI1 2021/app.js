var StylesEnum;
(function (StylesEnum) {
    StylesEnum["Style1"] = "styl1.css";
    StylesEnum["Style2"] = "styl2.css";
})(StylesEnum || (StylesEnum = {}));
const generateStyleLinks = () => {
    const parent = document.querySelector('nav ul');
    Object.values(StylesEnum).forEach((value) => {
        let child = document.createElement('button');
        child.innerText = value;
        child.onclick = () => enqueueStyle(value);
        parent.appendChild(child);
    });
};
const enqueueStyle = (style) => {
    document.querySelector('#custom-style')?.remove();
    const link = document.createElement('link');
    link.rel = 'stylesheet';
    link.href = style;
    link.id = 'custom-style';
    document.querySelector('head').appendChild(link);
};
window.addEventListener('load', () => {
    enqueueStyle(StylesEnum.Style1);
    generateStyleLinks();
});
