import {Injectable} from '@angular/core';
import 'rxjs/add/operator/toPromise';
import {Observable} from "rxjs";
import {Http, Response, Headers, RequestOptions, URLSearchParams} from '@angular/http';
import 'rxjs/add/operator/toPromise';
import {Util} from "./Util";
//import {ApiUrl} from "./ApiUrl";


/***
 * 请求处理
 *
 * demo：
 *  this.httpService.getByAuth(url, {
      "newpid":"sss",
      "orid": "sss"
    }).toPromise().then(data => {

    }).catch(error => {

    });
 */
@Injectable()
export class HttpService {

  constructor(private http: Http) {


  }

  public getByAuth(url: string, paramMap?: any): Observable<Response> {
    console.log("======parms======"+JSON.stringify(paramMap));
    let headers = new Headers({
      'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8',
    });

    return Observable.fromPromise(
      this.http.get(url,
        new RequestOptions
        (
          {search:HttpService.buildURLSearchParams(paramMap),
          headers: headers}
        ))
        .toPromise().then(
          (result)=>{ return result;},
          (error) => { return error;}
          )
         );
    }

  public postByAuth(url: string, paramMap?: any): Observable<Response> {
    console.log("======parms======"+JSON.stringify(paramMap));
    let headers = new Headers({
      'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8',
      'Accept': 'application/json;charset=utf-8',
    });
    return this.http.post(url, HttpService.buildURLSearchParams(paramMap).toString(), new RequestOptions({headers: headers}))
  }

  public static buildURLSearchParams(paramMap): URLSearchParams {
    let params = new URLSearchParams();
    for (let key in paramMap) {
      let val = paramMap[key];
      if (val instanceof Date) {
        val = Util.dateFormat(val, 'yyyy-MM-dd hh:mm:ss')
      }
      params.set(key, val);
    }
    //params.set('ajax', 'true');
    return params;
  }

}
