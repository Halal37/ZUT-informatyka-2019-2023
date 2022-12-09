import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-list',
  templateUrl: './list.component.html',
  styleUrls: ['./list.component.css']
})

export class ListComponent implements OnInit {

  empList: Map<string, string> = new Map();

  constructor() {
  }

  ngOnInit() {
    for (var i = 0; i < localStorage.length; i++) {

      var key = <string>localStorage.key(i);

      this.empList.set(<string>localStorage.key(i), <string>localStorage.getItem(key));
    }
  }


  deleteValue(inputText: string) {
    localStorage.removeItem(inputText);
    window.location.reload();

  }

  onSubmit(inputText: string) {
    localStorage.setItem(<string><unknown>localStorage.length, inputText);
  }
}
