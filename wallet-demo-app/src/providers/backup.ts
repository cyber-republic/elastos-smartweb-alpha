import { Injectable } from '@angular/core';

@Injectable()
export class BackupProvider {
    
    public idsDownload(content,fileName): Promise<any> {
        return new Promise((resolve, reject) =>{
              this._download(content,fileName).then(() => {
              return resolve();
              })
          });
    }


     private _download(ew: any, fileName: string): Promise<any> {
     
        return new Promise((resolve, reject) => {
          let a = document.createElement("a");
          let blob = this.NewBlob(ew, 'text/plain;charset=utf-8');
          let url = window.URL.createObjectURL(blob);
    
          document.body.appendChild(a);
    
          a.href = url;
          a.download = fileName;
          a.click();
          window.URL.revokeObjectURL(url);
    
          return resolve();
        });
      }
    
      private NewBlob(data: any, datatype: string): any {
        let out;
        try {
          out = new Blob([data], {
            type: datatype
          });
        } catch (e) {
          if (e.name == "InvalidStateError") {
            // InvalidStateError (tested on FF13 WinXP)
            out = new Blob([data], {
              type: datatype
            });
          } else {
            // We're screwed, blob constructor unsupported entirely
          }
        }
        return out;
      };
}