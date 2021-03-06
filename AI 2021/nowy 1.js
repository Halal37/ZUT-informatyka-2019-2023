<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Creating Nodes</title>
</head>
<body>
    <ul id="nodes-list">
        <li id="current">Current Item</li>
    </ul>

    <button onclick="before()">Before</button>
    <button onclick="after()">After</button>
    <button onclick="replace()">Replace</button>

    <script>
        var counter = 0;

        function createListItem() {
            let newLi = document.createElement('li');
            newLi.innerText = `Item ${counter++}`;
            return newLi;
        }

        function before() {
            let currentLi = document.getElementById("current");
            let newLi = createListItem();
            currentLi.parentElement.insertBefore(newLi, currentLi);
        }

        function after() {
            let currentLi = document.getElementById("current");
            let newLi = createListItem();
            currentLi.parentElement.appendChild(newLi);
        }

        function replace() {
            let currentLi = document.getElementById("current");
            let newLi = createListItem();
            currentLi.parentElement.replaceChild(newLi, currentLi);
        }
    </script>
</body>
</html>