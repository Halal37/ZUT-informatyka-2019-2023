window.addEventListener("load", () => {   
    show_fun();
	menu_fun();
}, false);

function menu_fun() {
    const table = document.createElement("table");
    const tableB = document.createElement("tbody")
    const tableH = document.createElement("thead");
    const tableHR = document.createElement("tr");
    const tableBR = document.createElement("tr");
    
    tableH.appendChild(tableHR);
    
    const task_zm = document.createElement("input");
    task_zm.id = "task_zm";
    task_zm.type = "text";
    task_zm.required = "required";
	task_zm.placeholder="Zadanie";

    const day_zm = document.createElement("input");
    day_zm.id = "day_zm";
    day_zm.type = "date";
    day_zm.required = "";

    const add_zm = document.createElement("input");
    add_zm.value = "Dodaj/Edytuj";
    add_zm.id = "add_zm";
    add_zm.type = "button";
    add_zm.addEventListener("click", () => {add_fun( task_zm.value, day_zm.value)}, false);


    const tableTask = document.createElement("td");
    tableTask.appendChild(task_zm);
    const tableDay = document.createElement("td");
    tableDay.appendChild(day_zm);
    const delete_but = document.createElement("td");
    delete_but.appendChild(add_zm);


    tableBR.appendChild(tableTask);
    tableBR.appendChild(tableDay);
    tableBR.appendChild(delete_but);
    tableB.appendChild(tableBR);

    table.appendChild(tableH);
    table.appendChild(tableB);

    const currentTable = document.getElementById("table1");
    document.body.insertBefore(table, currentTable);
}

function search_fun(value) {
    let list = JSON.parse(window.localStorage.getItem("list"));

for(const [i,el] of list.entries()){
	if(el.task === value){
    let res=i;

    if(res !== -1) {
		show_fun_2(value);
		

    }}
}
}

function add_fun(task, day) {
    let list = JSON.parse(window.localStorage.getItem("list"));
    if(list === null) {
        list = [];
    }
    list.push(
        {
            "task" : task,
            "day" : day
        }
    );
    window.localStorage.setItem("list", JSON.stringify(list));
    show_fun();
} 



function remove_fun(id) {
    let list = JSON.parse(window.localStorage.getItem("list"));
    list.splice(id, 1);
    window.localStorage.clear();
    window.localStorage.setItem("list", JSON.stringify(list));
    show_fun();
}

function edit_fun(id, task, day) {
    let list = JSON.parse(window.localStorage.getItem("list"));
    list[id] = { "task" : task, "day" : day };
    window.localStorage.clear();
    window.localStorage.setItem("list", JSON.stringify(list));
    show_fun();
}

function show_fun() {
    if(document.getElementById("tableList") !== null) {
        document.getElementById("tableList").remove();
    }
    let list = JSON.parse(window.localStorage.getItem("list"));
    if(list === null) {
        return;
    }
    const table = document.createElement("table");
    table.id = "tableList";
    const searchInputField = document.createElement("input");
    searchInputField.id = "searchInput";
    searchInputField.type = "text";
    const searchButton = document.createElement("input");
    searchButton.id = "searchButton";
    searchButton.value = "Wyszukaj";
    searchButton.type = "button";
    searchButton.addEventListener("click", () => search_fun(searchInputField.value));
    table.appendChild(searchInputField);
    table.appendChild(searchButton);
    let cnt = 0;
    for(let el of list) {
        const tableBR = document.createElement("tr");
        tableBR.id = "listElement" + cnt;

        const tableTask = document.createElement("td");
        tableTask.appendChild(document.createTextNode(el.task));
        const tableDay = document.createElement("td");
        tableDay.appendChild(document.createTextNode(el.day));
        const delete_but = document.createElement("input");
        delete_but.id = "element " ;
        delete_but.value = "usun ";
        delete_but.type = "button";
        delete_but.cnt = cnt;
        delete_but.addEventListener("click", () => remove_fun(delete_but.cnt), false);
        const edit_but= document.createElement("input");
        edit_but.id = "editElement " ;
        edit_but.value = "edytuj";
        edit_but.type = "button";
        edit_but.cnt = cnt;
  
        task_zm = document.getElementById("task_zm");
        dayeInput = document.getElementById("day_zm");
        edit_but.addEventListener("click", () => edit_fun(edit_but.cnt, codeInput.value, task_zm.value, day_zm.value), false);

        tableBR.appendChild(tableTask);
        tableBR.appendChild(tableDay);
        tableBR.appendChild(delete_but);
        tableBR.appendChild(edit_but);
        table.appendChild(tableBR);
        cnt++;
    }
    const currentTable = document.getElementById("table2");
    document.body.insertBefore(table, currentTable);
}






function show_fun_2(value) {
    if(document.getElementById("tableList") !== null) {
        document.getElementById("tableList").remove();
    }
    let list = JSON.parse(window.localStorage.getItem("list"));
    if(list === null) {
        return;
    }
    const table = document.createElement("table");
    table.id = "tableList";
    const searchInputField = document.createElement("input");
    searchInputField.id = "searchInput";
    searchInputField.type = "text";
    const searchButton = document.createElement("input");
    searchButton.id = "searchButton";
    searchButton.value = "Wyszukaj";
    searchButton.type = "button";
    searchButton.addEventListener("click", () => search_fun(searchInputField.value));
    table.appendChild(searchInputField);
    table.appendChild(searchButton);
    let cnt = 0;
    for(let el of list) {
		if(el.task === value){
        const tableBR = document.createElement("tr");
        tableBR.id = "listElement" + cnt;

        const tableTask = document.createElement("td");
        tableTask.appendChild(document.createTextNode(el.task));
        const tableDay = document.createElement("td");
        tableDay.appendChild(document.createTextNode(el.day));
        const delete_but = document.createElement("input");
        delete_but.id = "element ";
        delete_but.value = "usun ";
        delete_but.type = "button";
        delete_but.cnt = cnt;
        delete_but.addEventListener("click", () => remove_fun(delete_but.cnt), false);
        const edit_but= document.createElement("input");
        edit_but.id = "editElement ";
        edit_but.value = "edytuj ";
        edit_but.type = "button";
        edit_but.cnt = cnt;
    
        task_zm = document.getElementById("task_zm");
        dayeInput = document.getElementById("day_zm");
        edit_but.addEventListener("click", () => edit_fun(edit_but.cnt, codeInput.value, task_zm.value, day_zm.value), false);
   
        tableBR.appendChild(tableTask);
        tableBR.appendChild(tableDay);
        tableBR.appendChild(delete_but);
        tableBR.appendChild(edit_but);
        table.appendChild(tableBR);
        cnt++;
    }
    const currentTable = document.getElementById("table2");
    document.body.insertBefore(table, currentTable);
	}

}