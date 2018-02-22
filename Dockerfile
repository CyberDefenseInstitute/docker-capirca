FROM python:2

RUN git clone --depth 1 https://github.com/google/capirca.git && \
    cd capirca && \
    python setup.py install && \
    rm -rf /capirca && \
    useradd -m user

USER user
WORKDIR /home/user/ACL

VOLUME ["/home/user/ACL"]
ENTRYPOINT ["python","-m"]
