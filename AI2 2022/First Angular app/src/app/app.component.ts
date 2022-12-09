import {Component, Input, OnInit} from '@angular/core';
import {RandomComponent} from "./random/random.component";
import {ListComponent} from "./list/list.component";

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit {
  text: string;

  constructor() {
    this.text = "Hello World!";
  }

  ngOnInit(): void {
  }
}
