import { Component, ViewChild } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { ChatService, ChatMessage } from "../../providers/chat-service/chat-service";
import { Events, Content } from 'ionic-angular';

/**
 * Generated class for the ChatPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@Component({
  selector: 'page-chat',
  templateUrl: 'chat.html',
})
export class ChatPage {
  @ViewChild(Content) content: Content;
  item = null;

  myId = '';
  friendId = '';

  editorMsg = '';

  msgList: ChatMessage[] = [];

  constructor(public navCtrl: NavController, public navParams: NavParams,
            private chatService: ChatService,
            private events: Events) {
    this.item = navParams.get("item");
    this.friendId = this.item.uid;
    this.myId = this.chatService.getUid();
  }

  ionViewDidLoad() {
    console.log('ionViewDidLoad ChatPage');
  }

  ionViewDidEnter() {
    //get message list
    this.getMsg();

    // Subscribe to received  new message events
    this.events.subscribe('chat:received', this.receiveMsgHandle);
  }

  ionViewDidLeave() {
    this.events.unsubscribe('chat:received', this.receiveMsgHandle);
  }

  receiveMsgHandle: any = (data) => {
    console.log("=== chat page receive new message: " + data.message);
    this.pushNewMsg(data);
  }

  getMsg() {
    // Get mock message list
    this.msgList = this.chatService.getMsgList();
    this.scrollToBottom();
  }

  sendMsg() {
    if (!this.editorMsg.trim()) return;

    // Mock message
    const id = Date.now().toString();
    let newMsg: ChatMessage = {
      messageId: Date.now().toString(),
      userId: this.myId,
      userAvatar: './assets/imgs/avatar.png',
      toUserId: this.friendId,
      time: Date.now(),
      message: this.editorMsg,
      status: 'pending'
    };

    this.pushNewMsg(newMsg);
    this.editorMsg = '';

    this.chatService.sendMsg(newMsg)
    .then(() => {
      let index = this.getMsgIndexById(id);
      if (index !== -1) {
        this.msgList[index].status = 'success';
      }
    })
  }

  pushNewMsg(msg: ChatMessage) {
    const userId = this.myId,
    toUserId = this.friendId;
    // Verify user relationships
    if (msg.userId === userId && msg.toUserId === toUserId) {
      this.msgList.push(msg);
    } else if (msg.toUserId === userId && msg.userId === toUserId) {
      this.msgList.push(msg);
    }
    this.scrollToBottom();
  }

  getMsgIndexById(id: string) {
    return this.msgList.findIndex(e => e.messageId === id)
  }

  scrollToBottom() {
    setTimeout(() => {
      if (this.content.scrollToBottom) {
        this.content.scrollToBottom();
      }
    }, 400)
  }

  getTime(time): string {
    var date = new Date();
    date.setTime(time);
    return date.toLocaleTimeString();
  }

}
