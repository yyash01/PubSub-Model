import { fireEvent } from 'c/pubSubConnector';


export const publisherFunc = (pageRef, data) => {
    console.log('Hi JS publisherFunc');
    fireEvent(pageRef, 'EventFromPublisher', data);
};