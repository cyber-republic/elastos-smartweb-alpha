import { Injectable, isDevMode } from '@angular/core';

import * as _ from 'lodash';

/**
 * 日志控制
 */
@Injectable()
export class Logger {
  /* tslint:disable */
  public static levels: any;
  public static weight: any;
  public static logs: any[];

  constructor() {
    Logger.logs = [];
    Logger.levels = [
      { level: 'error', weight: 1, label: 'Error' },
      { level: 'warn', weight: 2, label: 'Warning' },
      { level: 'info', weight: 3, label: 'Info', default: true },
      { level: 'debug', weight: 4, label: 'Debug' }
    ];

    // Create an array of level weights for performant filtering.
    Logger.weight = {};
    for (let i = 0; i < Logger.levels.length; i++) {
      Logger.weight[Logger.levels[i].level] = Logger.levels[i].weight;
    }
  }

  public static error(message?: any, ...optionalParams: any[]): void {
    let msg = '[error] ' + (_.isString(message) ? message : JSON.stringify(message));
    console.log(msg, ...optionalParams);
    let args = Logger.processingArgs(arguments);
    Logger.add('error', args);
  }

  public static debug(message?: any, ...optionalParams: any[]): void {
    let msg = '[debug] ' + (_.isString(message) ? message : JSON.stringify(message));
    if (isDevMode()) console.log(msg, ...optionalParams);
    let args = Logger.processingArgs(arguments);
    Logger.add('debug', args);
  }

  public static info(message?: any, ...optionalParams: any[]): void {
    let msg = '[info] ' + (_.isString(message) ? message : JSON.stringify(message));
    if (isDevMode()) console.log(msg, ...optionalParams);
    let args = Logger.processingArgs(arguments);
    Logger.add('info', args);
  }

  public static warn(message?: any, ...optionalParams: any[]): void {
    let msg = '[warn] ' + (_.isString(message) ? message : JSON.stringify(message));
    if (isDevMode()) console.log(msg, ...optionalParams);
    let args = Logger.processingArgs(arguments);
    Logger.add('warn', args);
  }

  public static getLevels(): any {
    return Logger.levels;
  }

  public static getWeight(weight): any {
    return _.find(Logger.levels, l => {
      return l.weight == weight;
    });
  }

  public static getDefaultWeight(): any {
    return _.find(Logger.levels, l => {
      return l.default;
    });
  }

  public static add(level, msg): any {
    msg = msg.replace('/xpriv.*/', '[...]');
    msg = msg.replace('/walletPrivKey.*/', 'walletPrivKey:[...]');
    Logger.logs.push({
      timestamp: new Date().toISOString(),
      level,
      msg
    });
  }

  /**
   * Returns logs of <= to filteredWeight
   * @param {number} filteredWeight Weight (1-4) to use when filtering logs. optional
   */
  public static get(filterWeight?: number): any {
    let filteredLogs = Logger.logs;
    if (filterWeight != undefined) {
      filteredLogs = _.filter(Logger.logs, l => {
        return Logger.weight[l.level] <= filterWeight;
      });
    }
    return filteredLogs;
  }

  public static processingArgs(argsValues: any) {
    var args = Array.prototype.slice.call(argsValues);
    args = args.map(v => {
      try {
        if (typeof v == 'undefined') v = 'undefined';
        if (!v) v = 'null';
        if (typeof v == 'object') {
          v = v.message ? v.message : JSON.stringify(v);
        }
      } catch (e) {
        // tslint:disable-next-line:no-console
        console.log('Error at log decorator:', e);
        v = 'undefined';
      }
      return v;
    });
    return args.join(' ');
  }
}
