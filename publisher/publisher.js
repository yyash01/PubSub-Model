import { fireEvent } from 'c/pubSubConnector';


export const publisherFunc = (pageRef, data) => {
    console.log('Hi JS yyash01 Added');
    fireEvent(pageRef, 'EventFromPublisher', data);
};
