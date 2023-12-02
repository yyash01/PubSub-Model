import { fireEvent } from 'c/pubSubConnector';


export const publisherFunc = (pageRef, data) => {
    console.log('Hi JS Yash Merge Conflict');
    fireEvent(pageRef, 'EventFromPublisher', data);
};