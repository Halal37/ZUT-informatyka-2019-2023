import { Component } from '@angular/core';
import {Router} from "@angular/router";

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'lab14d';

  constructor(
    private router: Router
  ) {}

  activeUrl(): string {
    return this.router.url;
  }
}
