import * as _ from 'lodash';



export default class {
  static result<T>(rs: T): Promise<T>{
    return new Promise((resolve)=>{
      _.delay(()=>{
        resolve(rs);
      }, 500);
    });
  }

};