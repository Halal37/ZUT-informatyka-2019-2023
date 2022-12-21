import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { Task } from './models/task';

@Injectable({
  providedIn: 'root'
})
export class TaskService {

  constructor(
    private http: HttpClient
  ) { }

  getTasks(archived = false): Observable<Task[]> {

    return this.http.get<Task[]>(
      `https://lab13.zecer.wi.zut.edu.pl/api/lw46577`,
      {
        params: {
          archived: archived
        }
      }
    )
  }

  postTask(task: Task) : Observable<any> {
    return this.http.post(`https://lab13.zecer.wi.zut.edu.pl/api/lw46577`, task);
  }

  deleteArchivedTask(task: Task): Observable<any> {
    return this.http.delete(`https://lab13.zecer.wi.zut.edu.pl/api/lw46577/${task.id}`)
  }

  putTask(task: Task): Observable<any> {
    return this.http.put(`https://lab13.zecer.wi.zut.edu.pl/api/lw46577/${task.id}`, task);
  }
}
