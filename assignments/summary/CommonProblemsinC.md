# Common Bugs in C Programs
 Memory-related bugs are among the most frightening because they
often manifest themselves at a distance, in both time and space, from the source of
the bug.        

Most of these bugs are caused by incorrect usage of pointers, hence we suggest you
to not use pointers, but in cases where the system call demands the usage of
pointers then the programmer should be aware of the problems that it might cause.

[![](https://mermaid.ink/img/eyJjb2RlIjoiZ3JhcGggVERcbkFbRGVyZWZlcmVuY2luZyBCYWQgUG9pbnRlcnNdLS0-QltSZWFkaW5nIFVuaW50aWFsaXNlZCBtZW1vcnldLS0-Q1xuQ1tBbGxvdyBTdGFjayBCdWZmZXIgT3ZlcmZsb3dzXS0tPkRbQXNzdW1pbmcgdGhhdCBQb2ludGVycyBhbmQgdGhlIE9iamVjdHMgVGhleSBwb2ludCB0byBBcmUgVGhlIFNhbWUgU2l6ZV0tLT5FXG5FW01ha2luZyBPZmYtQnktT25lIEVycm9yc10tLT5GW1JlZmVyZW5jaW5nIGEgUG9pbnRlciBJbnN0ZWFkIG9mIHRoZSBPYmplY3QgSXQgUG9pbnRzIHRvXS0tPkdcbkdbTWlzdW5kZXJzdGFuZGluZyBQb2ludGVyIEFyaXRobWV0aWNdLS0-SFtSZWZlcmVuY2luZyBOb25leGlzdGVudCBWYXJpYWJsZXNdLS0-SVxuSVtJbnRyb2R1Y2luZyBNZW1vcnkgTGVha3NdXG5cblxuXG4gICAgICBjbGFzc0RlZiBjbGFzczEgZmlsbDojRjRBNDYwLHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAgICBjbGFzc0RlZiBjbGFzczIgZmlsbDojRkZEQUI5LHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAgICBjbGFzc0RlZiBjbGFzczMgZmlsbDpcdFx0IzY0OTVFRCxzdHJva2U6IzMzMyxzdHJva2Utd2lkdGg6NHB4O1xuICAgICAgY2xhc3NEZWYgY2xhc3M0IGZpbGw6I2Y5ZixzdHJva2U6IzMzMyxzdHJva2Utd2lkdGg6NHB4O1xuICAgICAgY2xhc3NEZWYgY2xhc3M1IGZpbGw6XHQjRkZCNkMxLHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAiLCJtZXJtYWlkIjp7InRoZW1lIjoiZGVmYXVsdCJ9LCJ1cGRhdGVFZGl0b3IiOmZhbHNlfQ)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoiZ3JhcGggVERcbkFbRGVyZWZlcmVuY2luZyBCYWQgUG9pbnRlcnNdLS0-QltSZWFkaW5nIFVuaW50aWFsaXNlZCBtZW1vcnldLS0-Q1xuQ1tBbGxvdyBTdGFjayBCdWZmZXIgT3ZlcmZsb3dzXS0tPkRbQXNzdW1pbmcgdGhhdCBQb2ludGVycyBhbmQgdGhlIE9iamVjdHMgVGhleSBwb2ludCB0byBBcmUgVGhlIFNhbWUgU2l6ZV0tLT5FXG5FW01ha2luZyBPZmYtQnktT25lIEVycm9yc10tLT5GW1JlZmVyZW5jaW5nIGEgUG9pbnRlciBJbnN0ZWFkIG9mIHRoZSBPYmplY3QgSXQgUG9pbnRzIHRvXS0tPkdcbkdbTWlzdW5kZXJzdGFuZGluZyBQb2ludGVyIEFyaXRobWV0aWNdLS0-SFtSZWZlcmVuY2luZyBOb25leGlzdGVudCBWYXJpYWJsZXNdLS0-SVxuSVtJbnRyb2R1Y2luZyBNZW1vcnkgTGVha3NdXG5cblxuXG4gICAgICBjbGFzc0RlZiBjbGFzczEgZmlsbDojRjRBNDYwLHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAgICBjbGFzc0RlZiBjbGFzczIgZmlsbDojRkZEQUI5LHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAgICBjbGFzc0RlZiBjbGFzczMgZmlsbDpcdFx0IzY0OTVFRCxzdHJva2U6IzMzMyxzdHJva2Utd2lkdGg6NHB4O1xuICAgICAgY2xhc3NEZWYgY2xhc3M0IGZpbGw6I2Y5ZixzdHJva2U6IzMzMyxzdHJva2Utd2lkdGg6NHB4O1xuICAgICAgY2xhc3NEZWYgY2xhc3M1IGZpbGw6XHQjRkZCNkMxLHN0cm9rZTojMzMzLHN0cm9rZS13aWR0aDo0cHg7XG4gICAiLCJtZXJtYWlkIjp7InRoZW1lIjoiZGVmYXVsdCJ9LCJ1cGRhdGVFZGl0b3IiOmZhbHNlfQ)        
 The Link for the details can be found [**Here**](https://gitlab.iotiot.in/newbies/iot-internship-feb-20/module2/wikis/4.2-Common-programming-errors)