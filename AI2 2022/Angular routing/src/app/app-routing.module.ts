import {NgModule} from '@angular/core';
import {RouterModule, Routes} from '@angular/router';
import {DetailsComponent} from "./details/details.component";
import {NotFoundComponent} from "./not-found/not-found.component";
import {AddPersonComponent} from "./add-person/add-person.component";
import {ListComponent} from "./list/list.component";
import {RouterTestingModule} from "@angular/router/testing";

const routes: Routes = [{path: 'details/:id', component: DetailsComponent},
  {path: '', component: ListComponent},
  {path: 'add', component: AddPersonComponent},
  {path: '**', component: NotFoundComponent},];

@NgModule({
  imports: [RouterModule.forRoot(routes), RouterTestingModule,],
  exports: [RouterModule]
})
export class AppRoutingModule {
}
