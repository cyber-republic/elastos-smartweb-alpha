/**
 * Created by yanxiaojun617@163.com on 3-12.
 */
import {Injectable} from '@angular/core';
//import {Validators as angularValidators, AbstractControl} from '@angular/forms';

@Injectable()
export class Util {

  /*E-mail*/
  static email = function (text) {
    const email = /[a-z]([a-z0-9]*[-_]?[a-z0-9]+)*@([a-z0-9]*[-_]?[a-z0-9]+)+[\\.][a-z]{2,3}([\\.][a-z]{2})?/;
    return email.test(text);
  };

  static phone = function (text) {
    const mPattern = /^((13[0-9])|(14[5|7])|(15([0-3]|[5-9]))|(18[0,5-9]))\d{8}$/;
    return mPattern.test(text);
  };

  static username = function (text) {
    var uPattern = /^[a-zA-Z0-9_-]{4,16}$/;
    return uPattern.test(text);
  };

  static password = function (text) {
    var pPattern = /^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,16}$/;
    return pPattern.test(text);
  };
  static number = function (text) {
    // var numPattern = /^(([1-9]\d*)|0)(\.\d{1,2})?$"/;
    // var numPattern = /^-?\d*\.?\d+$/;
    var numPattern = /^(([1-9]\d*)|\d)(\.\d{1,2})?$/;
    return numPattern.test(text);
  };

  public static isNull(data): boolean {
    return (data === '' || data === undefined || data === null) ? true : false;
  }

  public static isMnemonicValid(mnemonicStr): boolean {
    return mnemonicStr.split(/[\u3000\s]+/).length == 12 ? true : false
  }

  public static isAddressValid(address): boolean {
    return address.length == 34 ? true : false
  }


  public static isEmptyObject(obj): boolean {
    for (let key of obj ) {
      if(obj.hasOwnProperty(key)){
        return false;
      }
    }
    return true;
  }

  /**
   * 格式化日期
   * sFormat：日期格式:默认为yyyy-MM-dd     年：y，月：M，日：d，时：h，分：m，秒：s
   * @example  dateFormat(new Date(),'yyyy-MM-dd')   "2017-02-28"
   * @example  dateFormat(new Date(),'yyyy-MM-dd hh:mm:ss')   "2017-02-28 09:24:00"
   * @example  dateFormat(new Date(),'hh:mm')   "09:24"
   * @param date 日期
   * @param sFormat 格式化后的日期字符串
   * @returns {String}
   */
  static dateFormat(date: Date, sFormat: String = 'yyyy-MM-dd'): string {
    let time = {
      Year: 0,
      TYear: '0',
      Month: 0,
      TMonth: '0',
      Day: 0,
      TDay: '0',
      Hour: 0,
      THour: '0',
      hour: 0,
      Thour: '0',
      Minute: 0,
      TMinute: '0',
      Second: 0,
      TSecond: '0',
      Millisecond: 0
    };
    time.Year = date.getFullYear();
    time.TYear = String(time.Year).substr(2);
    time.Month = date.getMonth() + 1;
    time.TMonth = time.Month < 10 ? "0" + time.Month : String(time.Month);
    time.Day = date.getDate();
    time.TDay = time.Day < 10 ? "0" + time.Day : String(time.Day);
    time.Hour = date.getHours();
    time.THour = time.Hour < 10 ? "0" + time.Hour : String(time.Hour);
    time.hour = time.Hour < 13 ? time.Hour : time.Hour - 12;
    time.Thour = time.hour < 10 ? "0" + time.hour : String(time.hour);
    time.Minute = date.getMinutes();
    time.TMinute = time.Minute < 10 ? "0" + time.Minute : String(time.Minute);
    time.Second = date.getSeconds();
    time.TSecond = time.Second < 10 ? "0" + time.Second : String(time.Second);
    time.Millisecond = date.getMilliseconds();

    return sFormat.replace(/yyyy/ig, String(time.Year))
      .replace(/yyy/ig, String(time.Year))
      .replace(/yy/ig, time.TYear)
      .replace(/y/ig, time.TYear)
      .replace(/MM/g, time.TMonth)
      .replace(/M/g, String(time.Month))
      .replace(/dd/ig, time.TDay)
      .replace(/d/ig, String(time.Day))
      .replace(/HH/g, time.THour)
      .replace(/H/g, String(time.Hour))
      .replace(/hh/g, time.Thour)
      .replace(/h/g, String(time.hour))
      .replace(/mm/g, time.TMinute)
      .replace(/m/g, String(time.Minute))
      .replace(/ss/ig, time.TSecond)
      .replace(/s/ig, String(time.Second))
      .replace(/fff/ig, String(time.Millisecond))
  }


}
